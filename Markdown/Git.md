初始化

```
git init //初始化仓库
git clone //克隆仓库
```

编辑与提交

```
git add //添加文件
git mv //重命名文件
git rm //移除文件
git commit //提交修改
```

查看

```
git branch //添加修改分支
git checkout //跳转当前分支
git status //查看暂存信息
git log //查看日志
```

设置

```
git config list
git config get <name>
git config set <name> <value>
git config unset <name>
git config edit
```

远程仓库管理

```
git remote show <name>
git remote add <name> <url>
git remote rename <old> <new>
git remote remove <name>
git remote get-url <name>
git remote set-url <name> <newurl>
```

远程仓库拉取与推送

```
git fetch
git push
git pull
```

