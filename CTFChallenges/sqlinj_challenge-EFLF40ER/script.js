//check the script tag on website

<script>

function remapEnter(id, fun) {
  var el = document.getElementById(id);
  if (el) {
    el.addEventListener("keypress", function(event) {
      if (event.key === "Enter") {
        event.preventDefault();
        fun();
      }
    });
  }
}
  
function checkPassword() {
  if (CryptoJS.MD5(document.getElementById('passwordid').value) == 'eca24752946e35e46870662c1738e85b') {
    location.href="fulldictionary.php";
  } else {
    document.getElementById('error-message').innerHTML = "Password incorrect";
    errorModal.toggle();
  }
} 

function searchQuery (){
  let value = document.getElementById('searchid').value;
  if (value.includes("href")) {
    document.getElementById('resid').innerHTML = "Sorry, you cannot look for strings containing 'href' (are you trying to inject some code?)";
  } else {
    document.getElementById('resid').innerHTML = "Word <strong>"  + value + "</strong> not accepted. You have 0 remaining words: upgrade your plan!";
    document.getElementById('resid').classList.remove("invisible");
  }
}

remapEnter('passwordid', checkPassword);
remapEnter('searchid', searchQuery);
var errorModal = new bootstrap.Modal(document.getElementById('error-modal'), {});
  </script>
