// Nate Armstrong
// CS 4010 Quiz 1

// 1.
document.getElementById('name').innerHTML = 'Nate Armstrong';

// 2.
document.getElementById('triggeralert').onclick = function() { alert('Foo Bar!') }

// 3.
document.getElementById('triggerrandom').onclick = function() {
  document.getElementById('randomnumber').value = Math.floor(Math.random() * 10);
}

// 4.
var updateList = function() {
  var listsize = document.getElementById('listsize').value;
  var ul = document.getElementById('itemlist');
  ul.innerHTML = '';
  if (Number(listsize) > 0)
  {
    var i;
    for (i=1; i <= listsize; i++)
    {
      ul.innerHTML += '<li>Item ' + i + '</li>';
    }
  }
}
document.getElementById('triggerlist').onclick = updateList;
