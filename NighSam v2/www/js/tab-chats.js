angular.module('starter')

.controller('ChatsCtrl', function($scope, Chats) {
	var ctrl = this;
	
	ctrl.chats = Chats.all();

	ctrl.remove = function(chat) {
    	Chats.remove(chat);
  	};
})

.controller('ChatDetailCtrl', function($scope, $stateParams, Chats) {
  $scope.chat = Chats.get($stateParams.chatId);
})