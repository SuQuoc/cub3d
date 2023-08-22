# cub3d

Small 3D game using raycastig.



WOLFENSTEIN:
![image](https://github.com/SuQuoc/cub3d/assets/116435885/550abaa6-026d-4bd1-bc2e-e87188c6b089)





##Instructions
1. Clone the repository
2. Make sure you a have the c-compiler cc and run the make command
3. Execute the programm: "./cubed your_map_file"
4. Have fun and good luck



##Controls
- W, A, S, D
- left and right arrow key to rotate view
- ESC and "X-button" on top right window corner to end the game



GIT BRANCHING:


![image](https://github.com/SuQuoc/cub3d/assets/116435885/dd7b1e16-1a38-46cd-bb16-ba7cc509d45a)



Standard cmds like add, commit pull will only affect the bracnh u are in!

git checkout "branchname"     = switches branch to "branchname"
git checkout -b "branchname"  = creates a branch and checksout (switches) into it
git branch -d "branchname"    = deletes a branch if it was merged to main, you must be in main branch for the cmd
git branch -D "branchname"    = deletes a branch even if not merged to main
git branch -a                 = shows all branches and in which u are currently in



Merging:
You have to be in the main branch for merging branches into main!

git merge "branchname"


LOCAL AND REMOTE BRANCH
When you use git branch -d branchname to delete a branch, it deletes the local branch, but the remote tracking branch (if it exists) will still be visible when you use git branch -a.
The reason is that git branch -a shows both local and remote branches. Even though you've deleted the local branch using -d, the remote tracking branch still exists in your local repository until you explicitly remove it.

To remove the remote tracking branch, you can use the following command:
git push origin --delete branchname
