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
  // Initialize Firebase
  firebase.initializeApp(firebaseConfig);
  firebase.analytics();

  const auth = firebase.auth();