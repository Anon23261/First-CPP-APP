#!/bin/bash

# Find all HTML files in the docs/html directory and fix their DOCTYPE
find docs/html -name "*.html" -type f -exec sed -i '1i<!DOCTYPE html>' {} \;
find docs/html -name "*.html" -type f -exec sed -i '1,2{/^$/d}' {} \;
