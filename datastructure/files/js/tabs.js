function showContent(event, headerName) {
  var i, tabcontent, tab1;
  tabcontent = document.getElementsByClassName("tabC");
  for (i = 0; i < tabcontent.length; i++) {
    tabcontent[i].style.display = "none";
  }
  tab1 = document.getElementsByClassName("tab1");
  for (i = 0; i < tab1.length; i++) {
    tab1[i].className = tab1[i].className.replace(" active", "");
  }
  document.getElementById(headerName).style.display = "block";
  event.currentTarget.className += " active";
}

function showArrays(event, headerName) {
    var i, tabcontent, tab2;
    tabcontent = document.getElementsByClassName("tabC2");
    for (i = 0; i < tabcontent.length; i++) {
      tabcontent[i].style.display = "none";
    }
    tab2 = document.getElementsByClassName("tab2");
    for (i = 0; i < tab2.length; i++) {
      tab2[i].className = tab2[i].className.replace(" active", "");
    }
    document.getElementById(headerName).style.display = "block";
    event.currentTarget.className += " active";
}

function showLinkedList(event, headerName) {
  var i, tabcontent, tab3;
  tabcontent = document.getElementsByClassName("tabC3");
  for (i = 0; i < tabcontent.length; i++) {
    tabcontent[i].style.display = "none";
  }
  tab3 = document.getElementsByClassName("tab3");
  for (i = 0; i < tab3.length; i++) {
    tab3[i].className = tab3[i].className.replace(" active", "");
  }
  document.getElementById(headerName).style.display = "block";
  event.currentTarget.className += " active";
}

document.getElementById("defaultOpen1").click();
document.getElementById("defaultOpen2").click();
document.getElementById("defaultOpen3").click();
