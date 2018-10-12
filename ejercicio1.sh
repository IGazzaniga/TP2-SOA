#!/bin/bash
echo Ingrese el nombre del programa
read programa
if pgrep -x $programa > /dev/null
then
	echo "El programa se está ejecutando"
else
	echo "El programa NO se está ejecutando"
fi
