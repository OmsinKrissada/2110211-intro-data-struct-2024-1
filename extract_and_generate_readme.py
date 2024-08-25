#!/usr/bin//env python3

import re

quizes = {
    "Quiz 0 (sample quiz, no score)": ["d63_q1a_multi_insert", "d67_q0a_shoe_sizing"],
}
quiz_names = set()

with open("./scraped.html", encoding="utf8") as f:
    data = f.read()
data = data.replace("&ZeroWidthSpace;", "")
titles = re.findall(r"<strong>\n(.+)\n<span(.*)</span>\n</strong>", data)
ids = re.findall("/problems/(.*)/get_statement/(.+).pdf", data)
tasks = [
    {
        "id": a[0],
        "name": a[1].strip(),
        "pretty_name": b[0].strip(),
        "stars": b[1].count("star") - b[1].count("star_half") * 0.5,
    }
    for a, b in zip(ids, titles)
    if not a[1].strip().startswith("diglab")
]
# tasks.sort(key=lambda x: int(x["id"]))


def print_task_col(t):
    import os

    existing = os.listdir("./src")
    src = ""
    if t["name"] + ".cpp" in existing:
        src = t["name"] + ".cpp"
    elif t["name"] + ".c" in existing:
        src = t["name"] + ".c"
    print(
        "|".join(
            [
                f'{t["pretty_name"]}',
                f'[{t["name"]}.pdf](pdfs/{t["name"]}.pdf)',
                (f"[Solution](src/{src})" if src else "not done yet"),
                (
                    (int(t["stars"]) * "★" + int(t["stars"] % 1 * 2) * "☆")
                    if t["stars"]
                    else "-"
                ),
            ]
        ),
    )


def generateMarkdown():
    # Quiz Tables
    print(">[!NOTE]")
    print(">Only solutions that receive full score are included in this repository.")
    print("\n## Quizes")
    for quiz_name, task_names in quizes.items():
        print(f"### {quiz_name}")
        print("Name|PDF|My Solution|Stars")
        print("---|---|---|---")
        for tn in task_names:
            quiz_names.add(tn)
            t = [x for x in tasks if x["name"] == tn][0]
            print_task_col(t)

    # Practice Problems
    print("## Practice Problems")
    print("Name|PDF|My Solution|Stars")
    print("---|---|---|---")
    for t in tasks:
        if t["name"] in quiz_names:
            continue
        print_task_col(t)


def download():
    import os
    import time
    import random

    existing = os.listdir("./pdfs")

    for t in tasks:
        filename = t["name"] + ".pdf"
        if filename in existing:
            continue
        target_url = (
            f"https://grader.nattee.net/problems/{t['id']}/get_statement/{filename}"
        )
        # subprocess.run(['start','chrome'])
        # print("Opening", target_url)
        os.system(f"open {target_url}")
        time.sleep(0.3 + random.randint(1, 10) / 10 * 0.5)


def moveFromDownloadFolder():
    # print("Moving files to destination folder")
    import os

    existing = os.listdir("./pdfs")
    for t in tasks:
        if t["name"] + ".pdf" in existing:
            continue
        os.system(f"mv ~/Downloads/{t['name']} ./pdfs/{t['name'].strip()}.pdf")


download()
moveFromDownloadFolder()
generateMarkdown()
