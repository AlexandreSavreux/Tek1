function signout() {

    $.ajax({
        type: "POST",
        url: "/signout",
        success: function (result) {
            console.log(result);
        },
        error: function (result) {
            console.log(result);
        }
    });

    $.ajax({
        type: "GET",
        url: "/",
        success: function (result) {
            console.log(result);
            window.location.replace('/');
        },
        error: function (result) {
            console.log(result);
        }
    });
}

$('#btnSignout').on('click', signout);