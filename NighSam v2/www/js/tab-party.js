angular.module('starter')

.controller('PartyCtrl', function($scope, Parties) {
  var ctrl = this;

  ctrl.parties = Parties.all();
  
  ctrl.remove = function(party) {
    Parties.remove(party);
  };
})

.controller('PartyDetailCtrl', function($scope, $stateParams, $ionicModal, Parties, People) {
  $scope.party = Parties.get($stateParams.partyId)
  var ctrl = this;

  ctrl.people = People.all();
  ctrl.remove = function(person){
  	People.remove(person);
  }
  console.log(ctrl.people);

  var showModal = function(templateUrl) {
  	$ionicModal.fromTemplateUrl(templateUrl, {
  		scope: $scope,
  		animation: 'slide-in-up'
  	}).then(function(modal) {
  		$scope.modal = modal;
  		$scope.modal.show();
  	})
  }

  ctrl.clipSrc = 'img/video.mp4';

  ctrl.playVideo = function() {
  	showModal('templates/video-popover.html');
  }

  ctrl.closeModal = function() {
  	$scope.modal.hide();
  	$scope.modal.remove();
  }
})