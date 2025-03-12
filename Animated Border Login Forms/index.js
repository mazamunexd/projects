document.addEventListener('DOMContentLoaded', function() {
    document.getElementById('sign-up').addEventListener('click', function(e) {
        e.preventDefault();
        document.getElementById('login-form').style.display = 'none';
        document.getElementById('sign-up-form').style.display = 'block';
    });

    document.getElementById('forget-password').addEventListener('click', function(e) {
        e.preventDefault();
        document.getElementById('login-form').style.display = 'none';
        document.getElementById('forget-password-form').style.display = 'block';
    });

    document.getElementById('sign-up-form').addEventListener('submit', function(e) {
        e.preventDefault();
        // Simulate account creation logic here
        console.log('Sign up form submitted');
        // After creating the account, redirect to the login page
        document.getElementById('sign-up-form').style.display = 'none';
        document.getElementById('login-form').style.display = 'block';
    });

    document.getElementById('already-have-account').addEventListener('click', function(e) {
        e.preventDefault();
        // Redirect to the login form
        document.getElementById('sign-up-form').style.display = 'none';
        document.getElementById('login-form').style.display = 'block';
    });

    document.getElementById('forget-password-form').addEventListener('submit', function(e) {
        e.preventDefault();
        // Add forget password logic here
        console.log('Forget password form submitted');
        // Redirect to the login form after sending the email
        document.getElementById('forget-password-form').style.display = 'none';
        document.getElementById('login-form').style.display = 'block';
    });

    document.getElementById('sign-up-from-forgot').addEventListener('click', function(e) {
        e.preventDefault();
        // Redirect to the sign up form
        document.getElementById('forget-password-form').style.display = 'none';
        document.getElementById('sign-up-form').style.display = 'block';
    });

    document.getElementById('back-to-login').addEventListener('click', function(e) {
        e.preventDefault();
        // Redirect to the login form
        document.getElementById('forget-password-form').style.display = 'none';
        document.getElementById('login-form').style.display = 'block';
    });
});