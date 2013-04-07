#!/bin/bash

# Make sure you have the alias setup (use `drush sa` too see the aliases).
drush @pantheon.hakaveret.dev sql-drop -y
drush @pantheon.hakaveret.dev si -y kaveret --account-pass=admin
drush @pantheon.hakaveret.dev mi --all --user=1
drush @pantheon.hakaveret.dev genc 100 --types=offer,request --skip-fields=field_status
