function pageRedirect() {
    var x = document.getElementById("Spo2").value;
    var y= document.getElementById("HeartRate").value;
    if (x <=90) {
        window.open("http://192.168.1.6/4/on");
    }
    else {document.getElementById("O2").innerHTML= "O2 Level Fine!"}
}
