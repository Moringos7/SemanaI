// Inicialización de Firebase
var firebaseConfig = {
    apiKey: "AIzaSyA7Sqde65McpUOkmK9lyuoYivRuD8it1Y4",
    authDomain: "semanai-4ea99.firebaseapp.com",
    databaseURL: "https://semanai-4ea99.firebaseio.com",
    projectId: "semanai-4ea99",
    storageBucket: "semanai-4ea99.appspot.com",
    messagingSenderId: "227027138449",
    appId: "1:227027138449:web:d8a5840d8f95e29d09cc30",
    measurementId: "G-PRVKFTJHH6"
  };
  firebase.initializeApp(config);

  //Getter de valores a través de los ID asignados
  var rele1 = document.getElementById ("toogle1");
  var iluminacion = document.getElementById ("iluminacion");
  var movimiento = document.getElementById ("movimiento");
  var salir = document.getElementById("btnSalir") ;
  var correo = document.getElementById("inputEmail");
  var contraseña = document.getElementById("inputPassword");
  var inicio = document.getElementById("btnInicio");
  var divControles = document.getElementById("divControles");
  var divInicio = document.getElementById("divInicio");
  //Constante para simplificar el código
  const auth=firebase.auth();

//Listener para los valores de usuario y contraseña 
inicio.addEventListener ("click", function(){
	var contraseña_t = contraseña.value;
	var correo_t= correo.value;

	auth.signInWithEmailAndPassword(correo_t, contraseña_t).catch(function(error) {
	  // Handle Errors here.
	  var errorCode = error.code;
	  var errorMessage = error.message;
	  console.log(errorMessage);
	  // ...
	});

});

auth.onAuthStateChanged(function(user) {
  if (user) {
    $("#divInicio").addClass("collapse");
    $("#divControles").removeClass("collapse");
    
    //Escribimos en firebase los valores obtenidos con los listeners
    var fb_rele1 = firebase.database().ref().child("rele1");
   
    var fb_temperatura = firebase.database().ref().child("temperatura");
    var fb_movimiento = firebase.database().ref().child("movimiento");
    var fb_presencia = firebase.database().ref().child("presencia");
    var fb_iluminacion = firebase.database().ref().child("iluminacion");
    var fb_red = firebase.database().ref().child("red");
    var fb_green = firebase.database().ref().child("green");
    var fb_blue = firebase.database().ref().child("blue");

    //Variables para relevadores
    var t1=0;

//Bloque de Botones - Reley's
    fb_rele1.on("value",function (snapshot){
            /*Cambiará el aspecto del botón según el valor a través de las clases
            para dar un aspecto de activo */
            if(snapshot.val()==1){
                $("#toogle1").removeClass("btn-default").addClass("btn-success");
                t1=1;
            }
            else{
                $("#toogle1").removeClass("btn-success").addClass("btn-default");
                t1=0;
            }
        });
    rele1.addEventListener("click", function (){
      if (t1==1) fb_rele1.set(0);
      else fb_rele1.set(1);
    });

//Bloque de Slider
     var slider1 = new Slider('#ex1', {
      formatter: function(value) {
        return 'Current value: ' + value;
      }
    });

    fb_red.on("value",function (snapshot){
      slider1.setValue(snapshot.val());
    });

  
    slider1.on("slideStop", function(){
      fb_red.set(slider1.getValue());
    });
  

//Bloque card - Sensores

    fb_iluminacion.on("value",function (snapshot){
      iluminacion.innerHTML=snapshot.val() + " % de iluminacion"
    });

    fb_movimiento.on("value",function (snapshot){
      if (snapshot.val() == 1) {
        movimiento.innerHTML = "Hay Movimiento"
        $("#cardM").addClass("bg-info").addClass("text-white");
      }
      else {  
        movimiento.innerHTML = "No hay Movimiento"
        $("#cardM").removeClass("bg-info").removeClass("text-white");

      } 
    });
  } 
  
  else {
    // Cuando no se ha hecho login, solo muestra esta sección
     $("#divControles").addClass("collapse");
     $("#divInicio").removeClass("collapse");
  }
});

//botón de cerrar sesión
salir.addEventListener("click",function(){
	auth.signOut ();
});





