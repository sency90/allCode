function Create_cookie(){

   var cookie_name = 'hs_cookie_javascript';
   var cookie_value = 'hs_example';
   Create(cookie_name,cookie_value,30,"/");
}
function Create(name, value, expire, path){

     var date = new Date();
     date.setTime(date.getTime() + (expire * 24 * 60 * 60 * 1000));
     var expires = date.toUTCString();
     document.cookie = name + '=' + value + ';' +
                   'expires=' + expires + ';' +
                   'path=' + path + ';';
}
             
function Read_cookie(name){
   
      name = name + '=';
      var cookieData = document.cookie;
      var start = cookieData.indexOf(name);
      var value = '';
      if(start != -1){
         start += name.length;
         var end = cookieData.indexOf(';', start);
         if(end == -1)end = cookieData.length;
         value = cookieData.substring(start, end);
      }
      return unescape(value);
   }

function Update_cookie(){
   var cookie_name = 'hs_cookie_javascript';
   var cookie_value = 'hs_example';
   Create(cookie_name, cookie_value, 60, "/");

}
   
function Delete_cookie(){

 var cookie_name = 'hs_cookie_javascript';
 setpasttime(cookie_name);
}

function setpasttime(name){

   document.cookie = name + "=; expires=Thu, 01 Jan 1970 00:00:00 GMT; path=/";
}