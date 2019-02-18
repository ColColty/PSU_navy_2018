#!/bin/sh

echo ".travis.yml\n\
deploy.sh\n\
basic_tests.sh" >> .gitignore

echo "yes\n" | git remote add blih git@git.epitech.eu:/paul.tardivel@epitech.eu/PSU_navy_2018

echo "yes\n" | git push blih master:master