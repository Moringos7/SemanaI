//?Inicialización de Firebase con los valores dependiendo tu base
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
firebase.initializeApp(firebaseConfig);

//!Crear referencia a los elementos del HTMl
var luz = document.getElementById("luz");

var distanciaFrente = document.getElementById("distancia-frente");

var distanciaAtras = document.getElementById("distancia-atras");

var temperatura = document.getElementById("temperatura");


var rele1 = document.getElementById("rele1");
var rele2 = document.getElementById("rele2");

var salir = document.getElementById("btnSalir");
var correo = document.getElementById("inputEmail");
var contraseña = document.getElementById("inputPassword");
var inicio = document.getElementById("btnInicio");
var divControles = document.getElementById("divControles");
var divInicio = document.getElementById("divInicio");
//Constante para simplificar el código
const auth = firebase.auth();

//Listener para los valores de usuario y contraseña
inicio.addEventListener("click", function() {
  var contraseña_t = contraseña.value;
  var correo_t = correo.value;

  auth
    .signInWithEmailAndPassword(correo_t, contraseña_t)
    .catch(function(error) {
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
    // var fb_temperatura = firebase
    //   .database()
    //   .ref()
    //   .child("temperatura");
    // var fb_movimiento = firebase
    //   .database()
    //   .ref()
    // //   .child("movimiento");
    // var fb_presencia = firebase
    //   .database()
    //   .ref()
    //   .child("presencia");
    var fb_luz = firebase
      .database()
      .ref()
      .child("Luz");


    var fb_distanciaFrente = firebase
    .database()
    .ref()
    .child("Frente");

    var fb_distanciaAtras = firebase
    .database()
    .ref()
    .child("Atras");

    var fb_temperatura = firebase
    .database()
    .ref()
    .child("Temperatura");

    var fb_rele1 = firebase
    .database()
    .ref()
    .child("Ventana");
    // var fb_red = firebase
    //   .database()
    //   .ref()
    //   .child("red");
    // var fb_green = firebase
    //   .database()
    //   .ref()
    //   .child("green");
    // var fb_blue = firebase
    //   .database()
    //   .ref()
    //   .child("blue");

    //Variables para relevadores
    var t1 = 0;

    //Bloque de Botones - Reley's
    // fb_rele1.on("value", function(snapshot) {
    //   /*Cambiará el aspecto del botón según el valor a través de las clases
    //         para dar un aspecto de activo */
    //   if (snapshot.val() == 1) {
    //     $("#toogle1")
    //       .removeClass("btn-default")
    //       .addClass("btn-success");
    //     t1 = 1;
    //   } else {
    //     $("#toogle1")
    //       .removeClass("btn-success")
    //       .addClass("btn-default");
    //     t1 = 0;
    //   }
    // });
    rele1.addEventListener("click", function() {
      fb_rele1.set(1);
    });

    rele2.addEventListener("click", function() {
      fb_rele1.set(0);
    });

    //Bloque card - Sensores

    //!Setter en html que si funcionan
    fb_luz.on("value", function(snapshot) {
      var valLuz = snapshot.val();

      if (valLuz > 70) {
        luz.innerHTML = "Luces Apagadas";
      } else {
        luz.innerHTML = "Luces Encendidas";
      }
    });

    fb_distanciaFrente.on("value", function(snapshot) {
      var valDF = snapshot.val();

      if(valDF == 0) {
        distanciaFrente.innerHTML = "NA";
      } else {
        distanciaFrente.innerHTML = valDF + " cm";
      }
    });

    fb_distanciaAtras.on("value", function(snapshot) {
      var valDA = snapshot.val();

      if(valDA == 0) {
        distanciaAtras.innerHTML = "NA";
      } else {
        distanciaAtras.innerHTML = valDA + " cm";
      }
    });

    fb_temperatura.on("value", function(snapshot) {
      var valTemp = snapshot.val();

      if(valTemp < 60) {
        temperatura.innerHTML = "Frio";
      } else if( valTemp >= 60 && valTemp < 70) {
        temperatura.innerHTML = "Templado";
      }else{
        temperatura.innerHTML = "Caliente";
      }
    });

    // fb_movimiento.on("value", function(snapshot) {
    //   if (snapshot.val() == 1) {
    //     movimiento.innerHTML = "Hay Movimiento";
    //     $("#cardM")
    //       .addClass("bg-info")
    //       .addClass("text-white");
    //   } else {
    //     movimiento.innerHTML = "No hay Movimiento";
    //     $("#cardM")
    //       .removeClass("bg-info")
    //       .removeClass("text-white");
    //   }
    // });
  } else {
    // Cuando no se ha hecho login, solo muestra esta sección
    $("#divControles").addClass("collapse");
    $("#divInicio").removeClass("collapse");
  }
});

//botón de cerrar sesión
salir.addEventListener("click", function() {
  auth.signOut();
});
