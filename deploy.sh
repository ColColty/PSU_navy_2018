#!/bin/sh

echo ".travis.yml\n\
deploy.sh\n\
basic_tests.sh" >> .gitignore

git remote add blih git@git.epitech.eu:/paul.tardivel@epitech.eu/PSU_navy_2018

git push blih origin/master:refs/heads/master