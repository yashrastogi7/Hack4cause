function pageRedirect() {
    var x = document.getElementById("Spo2").value;
    var y= document.getElementById("HeartRate").value;
    if (x <=98 && y<=100) {
        window.location.href = "https://www.tutorialrepublic.com/";
    }
    else {document.getElementById("O2").innerHTML= "O2 Level Fine!"}
    
  }