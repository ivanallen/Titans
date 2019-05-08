### git 学习资料

https://learngitbranching.js.org/


### 如何提 pr

- 首先 fork 代码库到自己的仓库
- git clone 下来
- 建立一个开发分支 git branch -b dev
- 添加或修改代码
- git add 你修改或新增加的文件
- git commit -m "关于本次提交的描述，请使用英文"
- 提交到远程仓库的 dev 分支 git push origin dev:dev
- 点 pull request 发起 pr
- 等主仓库管理审核
