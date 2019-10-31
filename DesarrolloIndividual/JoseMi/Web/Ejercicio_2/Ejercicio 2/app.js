	var btn1 = document.getElementById("btn1");
	var btn2 = document.getElementById("btn2");
	var parrafo = document.getElementById("parrafo");
	var lista = document.getElementById("lista");
	var contador = 0;
	var fuente = 15;

	btn1.addEventListener("click", function() {
		contador++;
		if(contador==1){
		parrafo.innerHTML="Presionaste el botón #1 "+ contador + "vez"

		}
		else{

		}

		parrafo.innerHTML="Presionaste el botón #1  "+ contador + "veces"
	});

	btn2.addEventListener("click", function(){
		fuente++;
		lista.style.fontSize=fuente+"px";

	});