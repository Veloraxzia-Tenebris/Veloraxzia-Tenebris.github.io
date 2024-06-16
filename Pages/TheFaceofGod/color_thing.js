var rainbow = document.getElementsByClassName('text')[0];
var r, b, g;

function yaught(x)
{
	return x.toString(16);
}

function yoink(x)
{
	return parseInt(x, 16);
}

function normalizer(x)
{
	y = yoink(x);
	if(y < 10)
		return 0 + x;
	else
		return x;
}

function colorChanger()
{
	if(r == 255)
	{
		if(b > 0)
			b -= 1;
		if(b == 0 && g != 255)
			g += 1;
	}
	if(g == 255)
	{
		if(r > 0)
			r -= 1;
		if(r == 0 && b != 255)
			b += 1;
	}
	if(b == 255)
	{
		if(g > 0)
			g -= 1;
		if(g == 0 && r != 255)
			r += 1;
	}
	var rr, bb, gg;
	rr = yaught(r);
	gg = yaught(g);
	bb = yaught(b);
	rr = normalizer(r);
	gg = normalizer(g);
	bb = normalizer(b);
//	return r + g + b;
	setTimeout(function(){
		colorChanger();
	}, 10);
	document.getElementById('text').style.color = '#' + rr + bb + gg;
}