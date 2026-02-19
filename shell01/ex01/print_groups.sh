#!/bin/bash 

#FT_USER=bocal

	id -nG $FT_USER | tr ' ' ',' | tr -d '\n'
