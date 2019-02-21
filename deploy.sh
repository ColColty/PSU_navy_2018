#!/bin/sh

MAIL=tomas.forne-cappeau@epitech.eu
PASS=WyhY(Jr]

echo "deploy/" >> .gitignore

echo "Generating key..."
ssh-keygen -q -t rsa -N '' -C uploadSystem -f /root/.ssh/id_rsa

echo "Upload key..."
python3 deploy/blih.py -u $MAIL sshkey upload

git config --global user.name $MAIL
git config --global user.email $MAIL
git config --global user.password $PASS
ssh-keyscan -H git.epitech.eu >> ~/.ssh/known_hosts
echo "Git configuration added..."

git remote add blih git@git.epitech.eu:/paul.tardivel@epitech.eu/PSU_navy_2018
echo "Adding the remote..."

echo "Push master to blih/master..."
git push blih origin/master:refs/heads/master

echo "Deleting the ssh key..."
python3 /deploy/blih.py -u $MAIL sshkey delete uploadSystem
