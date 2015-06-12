defmodule HelloPhoenix.SubscriberView do
  use HelloPhoenix.Web, :view

  def render("index.json", %{subscribers: subscribers}) do
    subscribers
  end

end
