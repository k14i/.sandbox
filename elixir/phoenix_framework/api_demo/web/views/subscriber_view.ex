defmodule ApiDemo.Api.V1.SubscriberView do
  use ApiDemo.Web, :view

  def render("index.json", %{subscribers: subscribers}) do
    subscribers
  end

end
