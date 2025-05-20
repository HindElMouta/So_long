#!/bin/bash

SO_LONG=./so_long
MAP_DIR=tests

echo "🧪 Lancement des tests de cartes"

# Tester les cartes valides
echo ""
echo "✅ CARTES VALIDES"
for map in $MAP_DIR/valid/*.ber; do
	echo -n "Test $(basename $map): "
	$SO_LONG $map > /dev/null 2>&1 && echo "✅ OK" || echo "❌ FAILED"
done

# Tester les cartes invalides
echo ""
echo "❌ CARTES INVALIDES"
for map in $MAP_DIR/invalid/*.ber; do
	echo -n "Test $(basename $map): "
	$SO_LONG $map 2>&1 | grep -q "Error" && echo "✅ Error détectée" || echo "❌ PAS d'erreur"
done


# a faire 
# chmod +x test_maps.sh