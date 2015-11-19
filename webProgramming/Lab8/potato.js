// CSE 190 M Lab 8 (Mr. Potato Head) solution code

var WEB_APP = "potato.php";   // URL of web app to contact

document.observe("dom:loaded", function() {
    // set up listeners on all checkboxes
    var checkboxes = $$("#controls input");
    for (var i = 0; i < checkboxes.length; i++) {
        checkboxes[i].checked = false;
        checkboxes[i].observe("change", toggleAccessory);
    }

    // Exercise 4: reload saved initial state from web server ...
    new Ajax.Request(WEB_APP, {
        method: "get",
        onSuccess: ajaxGotState,
        onFailure: ajaxFailure,
        onException: ajaxFailure
    });
});

// Exercise 4
// called when state data arrives from Ajax request;
// sets up the appropriate checkbox / image state
function ajaxGotState(ajax) {
    $("status").innerHTML = "He is wearing: " + ajax.responseText;
    var accessories = getAccessoriesArray(ajax.responseText);
    for (var i = 0; i < accessories.length; i++) {
        if (accessories[i]) {
            $(accessories[i]).checked = true;
            $(accessories[i] + "_image").appear();
        }
    }
}

// called when any checkbox is checked/unchecked;
// toggles that accessory and sends the changes to the server
function toggleAccessory() {
    // Exercise 5: make the accessory appear / disappear ...
    if (this.checked) {
        $(this.id + "_image").appear();
    } else {
        $(this.id + "_image").fade();
    }
    
    // Exercise 6: save the state to the server using Ajax ...
    var accessoriesString = getAccessoriesString();
    $("status").innerHTML = "He is wearing: " + accessoriesString;
    new Ajax.Request(WEB_APP, {
        method: "post",
        onFailure: ajaxFailure,
        onException: ajaxFailure,
        parameters: { accessories: accessoriesString }
    });
}



// returns a string of all accessories that are selected on mr. potato head,
// such as "eyes ears moustache"
function getAccessoriesString() {
    var accessories = [];
    var checkboxes = $$("#controls input");
    for (var i = 0; i < checkboxes.length; i++) {
        if (checkboxes[i].checked) {
            accessories.push(checkboxes[i].id);
        }
    }
    return accessories.join(" ");
}

// converts a string of accessories such as "eyes ears moustache" into an array
// of strings such as ["eyes", "ears", "moustache"] and returns the array
function getAccessoriesArray(accessoriesString) {
    return accessoriesString.strip().split(" ");
}

// standard provided Ajax error-handling function
function ajaxFailure(ajax, exception) {
    alert("Error making Ajax request:" + 
          "\n\nServer status:\n" + ajax.status + " " + ajax.statusText + 
          "\n\nServer response text:\n" + ajax.responseText);
    if (exception) {
        throw exception;
    }
}