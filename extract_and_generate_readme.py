#!/usr/bin//env python3

import re
import os
import time
import random

quizes = {
    "Quiz 0 (sample quiz, no score)": ["d63_q1a_multi_insert", "d67_q0a_shoe_sizing"],
    "Quiz 1": ["d67_q1a_cpu_reservation", "d67_q1a_sort_position"],
}

remarks = {
    "d67_q0a_shoe_sizing": 'manual "binary search" instead of `lower_bound`',
    "d64_q1b_moving_median": "doesn't use `multiset`",
    "ex00m1": "PPxPPPPPPP",
    "d67_q1a_cpu_reservation": "PPPPPPPPPPTTTTTTTTTT",
}

quiz_names = set()

with open("./page.html", encoding="utf8") as f:
    data = f.read()
data = data.replace("&ZeroWidthSpace;", "")
titles = re.findall(r"<strong>\n(.+)\n<span(.*)</span>\n</strong>", data)
ids = re.findall("/problems/(.*)/get_statement/(.+).pdf", data)


src_root = "src/"
existing_files = os.listdir(src_root)
existing_subdirs = [x[0] for x in os.walk(src_root)]


def get_src(name):
    src = ""
    if name + ".cpp" in existing_files:
        src = src_root + name + ".cpp"
    elif name + ".c" in existing_files:
        src = src_root + name + ".c"
    elif src_root + name in existing_subdirs:
        src = src_root + name
    return src


tasks = [
    {
        "id": a[0],
        "name": a[1].strip(),
        "pretty_name": b[0].strip(),
        "stars": b[1].count("star") - b[1].count("star_half") * 0.5,
        "src": get_src(a[1].strip()),
    }
    for a, b in zip(ids, titles)
    if not a[1].strip().startswith("diglab")
]
# tasks.sort(key=lambda x: int(x["id"]))


def draw_task_col(t):
    return str(
        "|".join(
            [
                f'{t["pretty_name"]}',
                (
                    (int(t["stars"]) * "★" + int(t["stars"] % 1 * 2) * "☆")
                    if t["stars"]
                    else "-"
                ),
                f'[{t["name"]}.pdf](pdfs/{t["name"]}.pdf)',
                (f'[Solution]({t["src"]})' if t["src"] else "not done yet"),
                remarks[t["name"]] if t["name"] in remarks else "",
            ]
        ),
    )


def generateMarkdown():
    print(">[!NOTE]")
    print(
        ">My solutions shown here received full score unless explicitly stated otherwise."
    )
    print("\n## Quizes")

    header = "Name|Stars|PDF|My Solution|Remarks\n"
    header += "---|---|---|---|---"

    # Quiz Tables
    for quiz_name, task_names in quizes.items():
        print(f"### {quiz_name}")
        print(header)
        for tn in task_names:
            quiz_names.add(tn)
            t = [x for x in tasks if x["name"] == tn][0]
            print(draw_task_col(t))

    # Practice Problems
    lines = ""
    done = 0
    total = 0
    for t in tasks:
        if t["name"] in quiz_names:
            continue
        total += 1
        if t["src"]:
            done += 1
        lines += draw_task_col(t) + "\n"

    print(f"## Practice Problems ({done}/{total}, {round(done/total*100)}% done)")
    print(header)
    print(lines.strip())


def download():
    existing = os.listdir("./pdfs")

    first = True
    for t in tasks:
        filename = t["name"] + ".pdf"
        if filename in existing:
            continue
        if first:
            first = False
            # this is specific to my setup
            os.system("open -a Arc arc://settings/content/pdfDocuments")
            input()
        target_url = (
            f"https://grader.nattee.net/problems/{t['id']}/get_statement/{filename}"
        )
        # subprocess.run(['start','chrome'])
        # print("Opening", target_url)
        os.system(f"open {target_url}")
        time.sleep(0.3 + random.randint(1, 10) / 10 * 0.5)


def moveFromDownloadFolder():
    # print("Moving files to destination folder")

    existing = os.listdir("./pdfs")
    for t in tasks:
        if t["name"] + ".pdf" in existing:
            continue
        os.system(f"mv ~/Downloads/{t['name']} ./pdfs/{t['name'].strip()}.pdf")


download()
moveFromDownloadFolder()
generateMarkdown()
