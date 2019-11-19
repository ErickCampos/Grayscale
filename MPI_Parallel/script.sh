#!/bin/bash
cont=0;
while [ $cont -lt 2 ]; do
    mpirun -np 2 ./gray >> nada.txt;
    
    let cont=$cont+1;
done
