git pull
git status
echo -n "Do you want to continue (y/n)?"
read answer
while true
do
	case $answer in
	[yY]* ) git add -A
		echo -n "enter commit message : "
		read msg 
		git commit -m "${msg}"
		git push origin master
		break;;
	[nN]* ) echo "cancelled..."
		exit;;
	*) echo "please enter y or n"; break;;
	esac
done
