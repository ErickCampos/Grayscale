#!/bin/bash
cont=0;
while [ $cont -lt 5 ]; do
    ./gray >> nada.txt;
    
    let cont=$cont+1;
done
