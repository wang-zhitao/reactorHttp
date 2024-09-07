#!/usr/bin/env python3

import cgi
import cgitb
cgitb.enable()

form = cgi.FieldStorage()

name = form.getvalue('name', '未输入名字')

print("Content-Type: text/html")
print()
print(f"<html><body>你输入的名字是：{name}</body></html>")