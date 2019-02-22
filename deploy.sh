#!/bin/sh

MAIL="tomas.forne-cappeau@epitech.eu"
PASS="WyhY(Jr]"

echo "\n.travis.yml\nbasic_tests.sh\ndeploy.sh\n" >> .gitignore

git config --global user.name $MAIL
git config --global user.email $MAIL
git config --global user.password $PASS
echo "Git configuration added..."

echo "Adding the remote..."
git remote add blih git@git.epitech.eu:/paul.tardivel@epitech.eu/PSU_navy_2018

echo "Push master to blih/master..."
git push blih origin/master:refs/heads/master
