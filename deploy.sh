#!/bin/sh

MAIL="tomas.forne-cappeau@epitech.eu"
PASS="WyhY(Jr]"
export EPITECH_MAIL=$MAIL
export EPITECH_PASSWORD=$PASS

echo "*.yml" >> .gitignore
echo "*.sh" >> .gitignore
echo "*.py" >> .gitignore

ssh-keygen -q -t rsa -N '' -C uploadSystem -f /root/.ssh/id_rsa

echo "Uploading sshkey to blih"
python3 tmp/blih.py -u $MAIL sshkey upload /root/.ssh/id_rsa.pub

git config --global user.name $MAIL
git config --global user.email $MAIL
git config --global user.password $EPITECH_PASSWORD
ssh-keyscan -H git.epitech.eu >> ~/.ssh/known_hosts
echo "Git configuration added..."

echo "Adding the remote..."
git remote add blih git@git.epitech.eu:/paul.tardivel@epitech.eu/PSU_navy_2018

git commit -m "[UPDATE] Pushing the master branch from github to update the Epitech repo"

echo "Push master to blih/master..."
git push blih origin/master:refs/heads/master

echo "Deleting sshkey from blih"
python3 tmp/blih.py -u $MAIL sshkey delete uploadSystem
