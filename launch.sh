#!/bin/bash
PATH=$(printenv PATH)
make fclean && make all && ./exe
