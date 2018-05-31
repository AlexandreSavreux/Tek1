function signin() {
    var username = $('#usr').val();
    var password = $('#pwd').val();
    var log = {
        "username": username,
        "password": password
    }
    console.log(log);
    $.ajax({
        type: "POST",
        url: "/signin",
        data: JSON.stringify(log),
        dataType: 'json',
        contentType: 'application/json',
        success: function (result) {
            $("#Logged").replaceWith("<label id=\"Registered\">Logged !</label>");
            console.log(result);
        },
        error: function (result) {
            console.log(result);
        }
    });

    $.ajax({
        type: "GET",
        url: "/logged",
        success: function (result) {
            window.location.replace('/logged');
            console.log(result);
        },
        error: function (result) {
            console.log(result);
        }
    });
}

$('#btnSend').on('click', signin);