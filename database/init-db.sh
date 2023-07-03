#!/bin/bash

set -e

# Create the database if it doesn't exist
psql -v ON_ERROR_STOP=1 --username "$POSTGRES_USER" --dbname "$POSTGRES_DB" <<-EOSQL
    CREATE DATABASE IF NOT EXISTS "$POSTGRES_DB";
EOSQL
