// // CSE 190M Lab 5 (Pimpify)
// // JavaScript code for Pimp My Text lab

// function fontSize() {
//     $("sampletext").style.fontSize = "24pt";
// }

// function textStyle() {
//     if ($("pimp").checked) {
//         $("sampletext").style.fontWeight = "bold";
//         $("sampletext").style.textDecoration = "underline blink";
//         $("sampletext").style.color = "green";
//     } else {
//         $("sampletext").style.fontWeight = "normal";
//         $("sampletext").style.textDecoration = "none";
//         $("sampletext").style.color = "black";
//     }
// }

// function snoopify() {
//     $("sampletext").value = $("sampletext").value.toUpperCase();
//     $("sampletext").value = $("sampletext").value.split(".").join("-izzle.");
// }

var size = 10;



function fontSize(){

    var text = document.getElementById("sampletext");
    size = 20;
    text.style.fontSize = size + "pt";
}

function textStyle(){


    var text = document.getElementById("sampletext");
    var checkbox = document.getElementById("pimp");
    var image = document.getElementById("image");
    if (checkbox.checked){
        text.style.fontWeight = "bold";
        text.style.color = "green";
        text.style.textDecoration = "underline";
        image.src="http://www.cs.washington.edu/education/courses/190m/09sp/labs/5-pimpify/hundred-dollar-bill.jpg"
     
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