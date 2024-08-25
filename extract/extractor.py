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
tasks.sort(key=lambda x: int(x["id"]))


def generateMarkdown():
    import os

    existing = os.listdir("..")

    print(
        """<table>
    <tr>
        <th>Task Name</th>
        <th>Task PDF</th>
        <th>My Solution</th>
        <th>Stars</th>
    </tr>"""
    )
    # print("ID|Task Name|File name|Stars")
    # print("---|---|---|---")
    for t in tasks:
        # print(f"\n\t<!-- ID: {t['id']} -->")
        print(f"\t<tr>")
        print("\t\t<td>", end="")
        print(
            "</td>\n\t\t<td>".join(
                [
                    t["pretty_name"],
                    f'<a href="./pdfs/{t["name"]}.pdf">PDF</a>',
                    (
                        f'<a href="./{t["name"]}.cpp">Solution</a>'
                        if t["name"] + ".cpp" in existing
                        else "soon"
                    ),
                    (
                        (int(t["stars"]) * "★" + int(t["stars"] % 1 * 2) * "☆")
                        if t["stars"]
                        else "-"
                    ),
                ]
            ),
            end="",
        )
        print("</td>")
        print("\t</tr>")
    print("</table>")


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
