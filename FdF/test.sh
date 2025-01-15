#!/bin/bash

# testing all existing files
./fdf test_maps/10-2.fdf
sleep 5
./fdf test_maps/100-6.fdf
sleep 5
./fdf test_maps/20-60.fdf
sleep 5
./fdf test_maps/basictest.fdf
sleep 5
./fdf test_maps/elem.fdf
sleep 5
./fdf test_maps/mars.fdf
sleep 5
./fdf test_maps/pnp_flat.fdf
sleep 5
./fdf test_maps/pyramide.fdf
sleep 5
./fdf test_maps/10-2.fdf
sleep 5
./fdf test_maps/42.fdf
sleep 5
./fdf test_maps/elem2.fdf
sleep 5
./fdf test_maps/elem-fract.fdf
sleep 5
./fdf test_maps/pentenegpos.fdf
sleep 5
./fdf test_maps/pylone.fdf
sleep 5
./fdf test_maps/t1.fdf
sleep 5
./fdf test_maps/10-70.fdf
sleep 5
./fdf test_maps/50-4.fdf
sleep 5
./fdf test_maps/elem-col.fdf
sleep 5
./fdf test_maps/julia.fdf
sleep 5
./fdf test_maps/plat.fdf
sleep 5
./fdf test_maps/pyra.fdf
sleep 5
./fdf test_maps/t2.fdf
sleep 5

# testing error management
./fdf sources/FdF.c
./fdf
./fdf test_maps/t2.fdf test_maps/t2.fdf
./fdf test_maps/t1.fdf test_maps/t2.fdf
