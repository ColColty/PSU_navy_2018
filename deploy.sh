#!/bin/sh

echo ".travis.yml\n\
deploy.sh\n\
basic_tests.sh\n\
validate.txt" >> .gitignore

git remote add blih git@git.epitech.eu:/paul.tardivel@epitech.eu/PSU_navy_2018 < validate.txt

git push blih master:master < validate.txt