function timerFontSizeUp() {
    fontSize();
    setTimeout(fontSize, 500);
    
}

function fontSize(){
    setTimeout(fontSize, 500);
    var text = document.getElementById("sampletext");
    
    //get the current font size
    var upFontSize = parseFloat(window.getComputedStyle(text, null).getPropertyValue('font-size'));

    //let the font size 2 pt larger than its current size
    upFontSize = upFontSize + 2;
    text.style.fontSize = upFontSize + "pt";
}

function textStyle(){
    var text = document.getElementById("sampletext");
    var checkbox = document.getElementById("pimp");
    var img = document.getElementById("img01");
    if (checkbox.checked){
        text.style.fontWeight = "bold";
        text.style.color = "green";
        text.style.textDecoration = "underline";
        document.body.style.backgroundImage="url('./hundred-dollar-bill.jpg')";
     
    }
    else {
        text.style.fontWeight = "normal";
        text.style.textDecoration = "none";
        text.style.color = "black";       
    }
}

function snoopify(){
        var text = document.getElementById("sampletext");
        text.value = text.value.toUpperCase();
        text.value = text.value.split(".").join("-izzle.");
}