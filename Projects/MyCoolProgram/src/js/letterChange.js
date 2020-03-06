function upperLetters() 
{
    //get the input from text box
    var input = document.getElementById("textBoxOne").value;
    var length = input.length; //get length from input(which is texBoxOne.value)
    
    var original = input.toLowerCase();
    var newLine = "";
    var foundSpace = 0;//changed to 1 when a " " is found

    for(var i = 0; i < length; i++)
    {  
        if(original[i] == ' ')
        {
            foundSpace++;
        }
        
        if((foundSpace%2) != 0)
        {
            newLine = newLine + justOneLetter(original[i]);
            //console.log(newLine);
        }
        else
        {
            newLine = newLine + original[i];
        }
        foundSpace--;
    }
    
    document.getElementById("afterSub").innerHTML = newLine;
  
}

function spaceLetters() 
{
    //get input
    var input = document.getElementById("textBoxTwo").value;
    var length = input.length;//get input length
    
    //console.log(length);
    
    var original = input.toLowerCase();
    var newLine = "";
    var space = " ";

    for(var i = 0; i < length; i++)
    {   
    if(input[i]!= " ")
        newLine += (input[i] + space);        
        
    }
    
    document.getElementById("afterSub").innerHTML = newLine;
    
}
function upperSpaceLetters()
{
    //get the input from text box
    var input = document.getElementById("textBoxThree").value;
    var length = input.length; //get length from input(which is texBoxThree.value)
    
    var original = input.toLowerCase();
    var upperLine = "";
    var newLine = "";
    var space = " ";
    var foundSpace = 0;//changed to 1 when a " " is found
    
    //go through sentence
    for(var i = 0; i < length; i++)
    {    
    
    //if space is found
    if(original[i] == ' ')
        {
            foundSpace++;
        }
    //alternates through index lowercasing then uppercasing
    //if a space is found, it skips the spaces turn and make the next 
    //letter opposite of the letter before the space
    if((foundSpace%2) != 0)
        {
            upperLine = upperLine + justOneLetter(original[i]);
        }
    else
        {
            upperLine += original[i];
        }
        //change back so it go up down again
        foundSpace--;
    }
    
    
    for(var i = 0; i < length; i++)
    {   
    if(upperLine[i]!= " ")
        newLine += (upperLine[i] + space);        
    }

    document.getElementById("afterSub").innerHTML = newLine;
    
}

function justOneLetter(letter)
{
    letter = letter.toUpperCase();
    return letter;
}

function backwardsLetters()
{
    var input = document.getElementById("textBoxFour").value;
    var length = input.length;
    
    
    var newLine = "";
    
    for(var i = length-1; i != -1; i--)
    {
        newLine += input[i];
        
    }    
    
    
    document.getElementById("afterSub").innerHTML = newLine;
    
}

function speeveLetters()
{
    var input = document.getElementById("textBoxFive").value;
    var length = input.length;
    
    var sbeeve = "sbeeve";
    var SBEEVE = "SBEEVE";
    var x = 0;
    var newLine = "";
    
    for(var i = 0; i < length; i++)
    {
        //checks if the input has one of the sbeeve letters in it
        if(input[i] ==  sbeeve[x] || input[i] == SBEEVE[x])
        {   
            
            newLine += "(" + input[i];//adds front parentheses in front
            //checks if the next letter is also a sbeeve character
            for(var z = 1; (input[i+z] ==  sbeeve[x+z] || input[i+z] == SBEEVE[x+z]) && i+z < length; z)
            {
                newLine += input[i+z];
                //increment to keep track of where sbeeve and input is checking
                x++;
                i++;
            }
            //ending parentheses and skip the next letter because it is apart of sbeeve
            newLine += ")";
            x++;
            
        }
        else
            newLine += input[i];
    }   
    
    document.getElementById("afterSub").innerHTML = newLine;
    
}

function showDiv()
{
    var x = document.getElementById('afterSub');
        x.style.visibility = 'visible';
    var y = document.getElementById('copyButton');
        y.style.visibility = 'visible';
}

function hideDiv()
{
    var x = document.getElementById('afterSub');
        x.style.visibility = 'hidden';
    
    var y = document.getElementById('copyButton');
          y.style.visibility = 'hidden';
    
}

function copyText()
{
    if (document.selection) 
    { 
        var range = document.body.createTextRange();
        range.moveToElementText(document.getElementById('afterSub'));
        range.select().createTextRange();
        document.execCommand("copy"); 
    }
    
    else if (window.getSelection) 
    {
        var range = document.createRange();
        range.selectNode(document.getElementById('afterSub'));
        window.getSelection().addRange(range);
        document.execCommand("copy");
    }
}  


function openText(evt, text) {
  var i, tabcontent, tablinks;
  tabcontent = document.getElementsByClassName("tabcontent");
  for (i = 0; i < tabcontent.length; i++) {
    tabcontent[i].style.display = "none";
  }
  tablinks = document.getElementsByClassName("tablinks");
  for (i = 0; i < tablinks.length; i++) {
    tablinks[i].className = tablinks[i].className.replace(" active", "");
  }
  document.getElementById(text).style.display = "block";
  evt.currentTarget.className += " active";
}

//after finishing more implementations add a option to pick to combine some of choice
