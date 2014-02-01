#!/bin/sh
set -eu
./tiny-ini examples/sample.txt > /tmp/tiny-ini-sample.$$.out
grep -q "database.host=localhost" /tmp/tiny-ini-sample.$$.out
rm /tmp/tiny-ini-sample.$$.out
