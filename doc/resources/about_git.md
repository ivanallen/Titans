### git 学习资料

https://learngitbranching.js.org/


### 如何提 pr

- 首先 fork 代码库到自己的仓库（在 github 网页上操作）
- git clone 你自己的远程仓库（在你本地命令行操作）
- cd Titans 进入本地仓库目录
- 建立一个开发分支 git checkout -b dev
- 添加或修改代码
- git add 你修改或新增加的文件
- git commit -m "关于本次提交的描述，请使用英文"
- 提交到远程仓库的 dev 分支 git push origin dev:dev
- 点 pull request 发起 pr
- 等主仓库管理审核

### 如何保持自己的仓库最新（这一步非必须）

- 关联主库(如果你关联过了，就不用再次关联了。)

```
# 注意下面的关联的主库一定是我的，不是你自己的远程仓库，你直接复制命令就能用
$ git remote add core https://github.com/ivanallen/Titans
```

- 更新你的代码

```
# 从远程主库 core 拉 commit 到你自己的本地 master 分支
$ git pull core master

# 把你本地的 master 分支 push 到你自己的远程仓库 master 分支上
$ git push origin master
```
