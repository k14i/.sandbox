defmodule HelloPhoenix.SubscriberController do
  use HelloPhoenix.Web, :controller
  alias HelloPhoenix.Repo
  alias HelloPhoenix.Subscriber

  plug :action

  def index(conn, _params) do
    subscribers = Repo.all(Subscriber)
    render conn, subscribers: subscribers
  end

end
