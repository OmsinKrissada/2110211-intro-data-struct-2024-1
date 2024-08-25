#!/usr/bin/python

import re

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


def generateMarkdown():
    import os

    existing = os.listdir("../src")
    existing_quiz = os.listdir("../src/quiz")

    if t["name"] + ".cpp" in existing_quiz:
        src = t["name"] + ".cpp"
    elif t["name"] + ".c" in existing_quiz:
        src = t["name"] + ".c"

    print("Name|PDF|My Solution|Stars")
    print("---|---|---|---")
    for t in tasks:
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


def download():
    import os
    import time
    import random

    existing = os.listdir("../pdfs")

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

    existing = os.listdir("../pdfs")
    for t in tasks:
        if t["name"] + ".pdf" in existing:
            continue
        os.system(f"mv ~/Downloads/{t['name']} ../pdfs/{t['name'].strip()}.pdf")


download()
moveFromDownloadFolder()
generateMarkdown()
