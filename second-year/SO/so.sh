functie()
{
	echo "\n"
	echo "ID-ul Procesului este: $$"
	echo "Tipul Sistemului de operare este: " 
	cat /etc/issue.net 
	echo "Numarul de secunde de la executie: "
	$SECONDS
	echo "Calea curenta: "
	pwd
	echo "\n"
}

functie1()
{
	echo "\n"
	date +"Saptamana cu numarul %U din anul %Y"
	date +"Craciunul anul acesta este in ziua de %A anul acesta"
	echo "\n"
}

functie2()
{
	echo "\n"
	awk "FNR>=2 && FNR<=3" /etc/shells
	echo "\n"
}

functie3()
{
	echo "\n"
	echo $USERNAME
	export user=$(whoami)
	echo $user
	
	echo "\n"	 
}

functie4()
{
	echo "\n"
	tail -n 9 /etc/protocols
	echo "\n"	
}

functie5()
{
	echo "\n"
	grep "model name" /proc/cpuinfo
	grep "cache size" /proc/cpuinfo
	echo "\n"
	
}

functie6()
{
	echo "\n"
	ls /proc | grep '[a-zA-Z]'
	echo "\n"
}

functie7()
{
	echo "\n"
	ls /var/log | egrep '\.log$|\gz$'
	
	echo "\nNume log: "
	read logName
	
	echo "\nTextul cautat: "
	read text
	
	cautare_text "$logName" "$text"
	
}

cautare_text()
{
	echo "\n"
	grep "$2" "/var/log/$1"
	echo "\n"
}

while [ True ]
do

	echo "Meniu: "
	echo "1. Iesire "
	echo "2. Afisare PID,SO,Secunde de la executie, Calea Curent "
	echo "3. Afișarea numarului săptămânii din an, si a zilei săptămânii în care va fi Crăciunul în acest an"
	echo "4. Afișarea primelor 2 shell-urilor instalate în sistem"
	echo "5. Afișarea pentru toți utilizatorii din sistem a numelui de login, a user ID-ului, a numelui complet si a directorului de home"
	echo "6. Afişare ultimele linii începând cu linia 9 din fișierul /etc/protocols folosind comanda tail"
	echo "7. Afișare tip procesor şi mărimea cache-ului"
	echo "8. Scrieți comanda ls care afișează toate numele de directoare din directorul /proc care nu reprezintă imaginea unui proces pe disc"
	echo "9. Sa se afiseze toate fisierele de log. Sa se creeze o funcție care primește ca si parametrii cititi de la tastatura un nume de fișier de log (ori curent ori arhivat) și un text, si care va căuta si afișa liniile care conțin textul primit ca si parametru"
	echo "\n"
	echo "Optiunea ta: "
	read option

	
	case "$option" in
	
		"1") exit ;;
		"2") functie;;
		"3") functie1;;
		"4") functie2;;
		"5") functie3;;
		"6") functie4;;
		"7") functie5;;
		"8") functie6;;
		"9") functie7;;
	
	esac
done
