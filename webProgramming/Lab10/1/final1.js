window.onload = function() {
    for(var i=0; i<2;i++){
        var tables = document.getElementById("ad"+i);
        for (var j = 0; j < tables.rows.length; j+=2){
            tables.rows[j].style.color='white';
            tables.rows[j].style.backgroundColor='black';
        }
    }
};