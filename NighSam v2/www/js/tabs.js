angular.module('starter')

.controller('TabCtrl', function($scope) {
	var ctrl = this;

	ctrl.hide = function() {
		var user = JSON.parse(window.localStorage["user"] || '{}');

		if (user["pro"] == "true") {
			return "ng-show";
		}
		return "ng-hide";
	}
})