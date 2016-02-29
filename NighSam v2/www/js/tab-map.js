angular.module('starter')

.controller('MapCtrl', function($scope, $state, $cordovaGeolocation, Parties) {
  $scope.parties = Parties.all();
	var options = {timeout: 10000, enableHighAccuracy: true};
 


	$cordovaGeolocation.getCurrentPosition(options).then(function(position) {
		var latLng = new google.maps.LatLng(position.coords.latitude, position.coords.longitude);
 
      var markers = new Array()
    	var mapOptions = {
      		center: latLng,
      		zoom: 15,
      		mapTypeId: google.maps.MapTypeId.ROADMAP
    	};
      
        var infowindow = new google.maps.InfoWindow({
         content: "holding..."
        });

    	$scope.map = new google.maps.Map(document.getElementById("map"), mapOptions);
      var marker = new google.maps.Marker({
            position: latLng,
            map: $scope.map,
            icon: "http://maps.google.com/mapfiles/ms/icons/blue-dot.png",
            title: "hello world"
          }); 
 
        google.maps.event.addListener(marker, 'click', function () {
            infowindow.setContent("me");
            infowindow.open($scope.map, marker);
        });      

      var parties = $scope.parties;
      for (var i = 0; i < parties.length; i++)
      {
        var address = $scope.parties[i]["adresse"];

        var geocoder = new google.maps.Geocoder();

        geocoder.geocode({address: address}, function(results, status) {

        if (status == google.maps.GeocoderStatus.OK) 
        {

          var myResult = results[0].geometry.location; // reference LatLng value

          var marker = new google.maps.Marker({
            position: myResult,
            map: $scope.map,
            title: "hello world"
          }); 
          markers.push(marker);
          google.maps.event.addListener(marker, 'click', (function(marker, i) {
            return function() {
          infowindow.setContent(parties[i]["place"]);
          infowindow.open(map, marker);
        }
      })(marker, i));

        }       
      });
      }
      for (var i = 0; i < markers.length; i++) 
      {
        var m = markers[i];
        google.maps.event.addListener(m, 'click', function () {
          infowindow.setContent(party);
          infowindow.open($scope.map, m);
        });
      }



      //createMarker(myResult); // call the function that adds the marker

      //map.setCenter(myResult);

      //map.setZoom(17);

  //});

    
      

		 //Wait until the map is loaded
		google.maps.event.addListenerOnce($scope.map, 'idle', function(){
 


  			// var marker = new google.maps.Marker({
     //  			map: $scope.map,
     //  			animation: google.maps.Animation.DROP,
     //  			position: latLng
  			// });      
		});
		
  	}, function(error){
    	console.log("Could not get location");
  	});
  	
})