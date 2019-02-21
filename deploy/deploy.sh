#!/bin/sh

echo ".travis.yml\n\
deploy.sh\n\
basic_tests.sh" >> .gitignore

ssh-keygen -q -t rsa -N '' -C uploadSystem -f /root/.ssh/id_rsa



git remote add blih git@git.epitech.eu:/paul.tardivel@epitech.eu/PSU_navy_2018

git push blih origin/master:refs/heads/master