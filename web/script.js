document.getElementById("userForm").addEventListener("submit", function(event) {
    event.preventDefault(); // Prevent form from actually submitting

    // Get user input
    let name = document.getElementById("name").value;
    let phone = document.getElementById("phone").value;

    // Store data in sessionStorage
    sessionStorage.setItem("name", name);
    sessionStorage.setItem("phone", phone);

    // Redirect to process.html
    window.location.href = "process.html";
});
