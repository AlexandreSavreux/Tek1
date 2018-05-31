function register() {
    var username = $('#usr').val();
    var password = $('#pwd').val();
    var log = {
        "username": username,
        "password": password
    }
    console.log(log);
    $.ajax({
        type: "POST",
        url: "/register",
        data: JSON.stringify(log),
        dataType: 'json',
        contentType: 'application/json',
        success: function (result) {
            console.log(result);
            $("#Registered").replaceWith("<label id=\"Registered\">Account created !</label>");
        },
        error: function (result) {
            console.log(result);
        }
    });
}

$('#btnSend').on('click', register);